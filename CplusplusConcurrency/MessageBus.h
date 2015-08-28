#pragma once

#include <string>
#include <functional>
#include <map>
#include "FunctionTraits.h"
#include "NonCopyable.h"
#include "Any.h"

class MessageBus : NonCopyable
{
public:
    template<typename F>
    void Attach(F&& f, const std::string& strTopic = "")
    {
        auto func = to_function(std::forward<F>(f));
        Add(strTopic, std::move(func));
    }

    template<typename R>
    void SendReq(const std::string& strTopic = "")
    {
        using function_type = std::function<R()>;
        std::string strMsgType = strTopic + typeid(function_type).name();
        auto range = m_map.equal_range(strMsgType);
        for (Iterator it = range.first; it != range.second; ++it)
        {
            auto f = it->second.AnyCast<function_type>();
            f();
        }
    }

    template<typename R, typename... Args>
    void SendReq(Args&&... args, const std::string& strTopic = "")
    {
        using function_type = std::function<R(Args...)>;
        std::string strMsgType = strTopic + typeid(function_type).name();
        auto range = m_map.equal_range(strMsgType);
        for (Iterator it = range.first; it != range.second; ++it)
        {
            auto f = it->second.AnyCast<function_type>();
            f(std::forward<Args>(args)...);
        }
    }

    template<typename R, typename... Args>
    void Remove(const std::string& strTopic = "")
    {
        using function_type = std::function<R(Args...)>;
        std::string strMsgType = strTopic + typeid(function_type).name();
        int count = m_map.count(strMsgType);
        auto range = m_map.equal_range(strMsgType);
        m_map.erase(range.first, range.second);
    }

private:
    template<typename F>
    void Add(const std::string& strTopic, F&& f)
    {
        std::string strMsgType = strTopic + typeid(F).name();
        m_map.emplace(std::move(strMsgType), std::forward<F>(f));
    }

private:
    std::multimap<std::string, Any> m_map;
    typedef std::multimap<std::string, Any>::iterator Iterator;
};