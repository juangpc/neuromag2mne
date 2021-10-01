#include "commandwatcher.hpp"
#include <iostream>
#include"thread.hpp"

CommandWatcher::CommandWatcher()
{

}

void CommandWatcher::connect()
{
    connect(COLLECTOR_PORT, COLLECTOR_PASS);
}

void CommandWatcher::connect(int port, std::string password)
{

}

void CommandWatcher::disconnect()
{

}

void CommandWatcher::registerCallback(std::string str, void (*func)(std::string))
{
    m_callbacks.push_back(CommandCallback(str, func));
}

void CommandWatcher::deleteCallback(std::string, void (*func)(std::string))
{
    
}

void CommandWatcher::deleteCallback(int index)
{
    if(index < m_callbacks.size()){
        m_callbacks.erase(m_callbacks.begin() + index);
    }
}

void CommandWatcher::showCallbacks()
{
    int i = 0;
    std::vector<CommandCallback>::iterator it;

    for(it = m_callbacks.begin(); it != m_callbacks.end(); it++, i++)
    {
        std::cout << "(" << i << ") - '" << m_callbacks.at(i).m_trigger << "'\n";
    }
}

void CommandWatcher::startWatching()
{

}

void CommandWatcher::stopWatching()
{

}