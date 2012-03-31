#ifndef XMLREAD_HPP
#define XMLREAD_HPP

#include <string>
#include <vector>
#include <QtXml>
#include <QFile>
#include <map>
#include "edge.hpp"
#include "node.hpp"
#include "mechanicalnode.hpp"

#include <iostream>
#include <QtGlobal>

class XmlRead
{
public:
    XmlRead(std::string);

    void parseGraph();

private:
    std::string filename;

};

#endif // XMLREAD_HPP
