#include "xmlread.hpp"

XmlRead::XmlRead(std::string inFilename)
{
    filename = inFilename;
}

void XmlRead::parseGraph()
{
    // Read from file
    QFile file(filename.c_str());
    if (!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Failed to open file for reading" << std::endl;
        return;
    }

    // Construct DOM tree
    QDomDocument doc;
    if (!doc.setContent(&file))
    {
        std::cout << "Failed to parse the file into a DOM tree" << std::endl;
        file.close();
        return;
    }
    file.close();

    // Create mapping
    QDomElement elem = doc.documentElement();

    if (elem.tagName() != "graphml")
    {
        std::cout << "File not graphml format" << std::endl;
        return;
    }

    elem = elem.firstChildElement();
    if (elem.tagName() != "graph")
        return;

    // Declare Some Variables and initialize some settings
    QString edgeDefault = elem.attribute("edgedefault");
    QString xmlNodeType;

    // Create the nodes
    elem = elem.firstChildElement();
    if (elem.tagName() != "nodes")
    {
        std::cout << "xml file not in correct format ... nodes need to be defined first" << std::endl;
        return;
    }
    else
    {
        xmlNodeType = elem.attribute("type");

    }

    std::map <int,MechanicalNode*>* mapping = new std::map <int,MechanicalNode*>();
    if (xmlNodeType == "mechanical")
    {
        for (QDomNode n = elem.firstChild(); !n.isNull(); n = n.nextSibling())
        {
            elem = n.toElement();
            std::cout << elem.tagName().toStdString() << std::endl;

        }
    }
}
