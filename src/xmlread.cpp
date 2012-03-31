#include "xmlread.hpp"

XmlRead::XmlRead(std::string inFilename)
{
    filename = inFilename;
}

std::map <int,MechanicalNode*>* XmlRead::parseGraph()
{
    // Read from file
    QFile file(filename.c_str());
    if (!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Failed to open file for reading" << std::endl;
        return NULL;
    }

    // Construct DOM tree
    QDomDocument doc;
    if (!doc.setContent(&file))
    {
        std::cout << "Failed to parse the file into a DOM tree" << std::endl;
        file.close();
        return NULL;
    }
    file.close();

    // Create mapping
    QDomElement elem = doc.documentElement();

    if (elem.tagName() != "graphml")
    {
        std::cout << "File not graphml format" << std::endl;
        return NULL;
    }

    elem = elem.firstChildElement();
    if (elem.tagName() != "graph")
        return NULL;

    // Declare Some Variables and initialize some settings
    QString edgeDefault = elem.attribute("edgedefault");

    std::map <int,MechanicalNode*>* mapping = new std::map <int,MechanicalNode*>();

    for (QDomNode t=elem.firstChild(); !t.isNull(); t = t.nextSibling())
    {
        elem = t.toElement();
        if (elem.tagName() == "nodes")
        {
            QString xmlNodeType = elem.attribute("type");
            if (xmlNodeType == "mechanical")
            {
                for (QDomNode n = elem.firstChild(); !n.isNull(); n = n.nextSibling())
                {
                    elem = n.toElement();
                    int id = elem.attribute("id").toInt();

                    MechanicalNode* newNode = new MechanicalNode(id);
                    mapping->insert(std::pair <int,MechanicalNode*> (id,newNode));

                    if (n.hasChildNodes())
                    {
                        for (QDomNode n_child = n.firstChild(); !n_child.isNull(); n_child = n_child.nextSibling())
                            elem = n_child.toElement();
                        if (elem.tagName() == "pos")
                        {
                            double x = elem.attribute("x").toDouble();
                            double y = elem.attribute("y").toDouble();
                            double z = elem.attribute("z").toDouble();
                            newNode->setPos(x,y,z);
                        }
                    }
                }
            }
        }
        else if (elem.tagName() == "edges")
        {
            int edgeID(0);
            for (QDomNode e = elem.firstChild(); !e.isNull(); e = e.nextSibling())
            {
                elem = e.toElement();

                int sourceID = elem.attribute("source").toInt();
                int targetID = elem.attribute("target").toInt();

                MechanicalNode* sourceNode = mapping->at(sourceID);
                MechanicalNode* targetNode = mapping->at(targetID);

                Edge* edge1 = new Edge(sourceNode,targetNode);
                sourceNode->addSuccessor(edge1);
                edge1->setEdgeID(edgeID);
                edgeID++;

                double costValue;
                QString cost = elem.attribute("cost");
                if (cost == "distance")
                {
                    double* pos1 = sourceNode->getPos();
                    double* pos2 = targetNode->getPos();
                    double deltaX = pos1[0] - pos2[0];
                    double deltaY = pos1[1] - pos2[1];
                    double deltaZ = pos1[2] - pos2[2];
                    cost = sqrt(deltaX*deltaX + deltaY*deltaY + deltaZ*deltaZ);
                }
                else if (cost == "jumps")
                {
                    costValue = 1;
                }
                else
                {
                    costValue = cost.toDouble();
                }
                edge1->setCost(costValue);

                if (edgeDefault == "undirected")
                {
                    Edge* edge2 = new Edge(targetNode,sourceNode);
                    targetNode->addSuccessor(edge2);
                    edge2->setEdgeID(edgeID);
                    edgeID++;
                    edge2->setCost(costValue);
                }
            }
        }
    }

    return mapping;
}
