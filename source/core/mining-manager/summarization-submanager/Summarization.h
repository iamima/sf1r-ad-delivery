#ifndef SF1R_MINING_MANAGER_SUMMARIZATION_SUBMANAGER_SUMMARIZATION_H
#define SF1R_MINING_MANAGER_SUMMARIZATION_SUBMANAGER_SUMMARIZATION_H

#include "summarization_types.h"

#include <am/bitmap/ewah.h>

namespace sf1r
{

/// @brief This class implements Summarization that stores a document identifier and
/// a list of summarization properties.
class Summarization
{
    typedef std::map<std::string, std::vector<std::pair<double, izenelib::util::UString> > > property_named_map;
    typedef izenelib::am::EWAHBoolArray<uint32_t> fingerprint_type;

public:
    typedef property_named_map::const_iterator property_const_iterator;
    typedef property_named_map::iterator property_iterator;

    Summarization()
    {
    }

    explicit Summarization(const fingerprint_type& fingerPrint)
    {
        fingerPrint_ = fingerPrint;
    }

    template <class ContainerType>
    explicit Summarization(const ContainerType& docid_list)
    {
        for (typename ContainerType::const_iterator it = docid_list.begin();
                it != docid_list.end(); ++it)
        {
            fingerPrint_.set(*it);
        }
    }
    template <class T1, class T2>
    explicit Summarization(const std::map<T1, T2>& docid_map)
    {
        for (typename std::map<T1, T2>::const_iterator it = docid_map.begin();
                it != docid_map.end(); ++it)
        {
            fingerPrint_.set(it->first);
        }
    }

    void setBit(uint32_t pos)
    {
        fingerPrint_.set(pos);
    }

    std::vector<std::pair<double, izenelib::util::UString> >& property(const std::string& propertyName)
    {
        return propertyList_[propertyName];
    }

    const std::vector<std::pair<double, izenelib::util::UString> >& property(const std::string& propertyName) const
    {
        static std::vector<std::pair<double, izenelib::util::UString> > empty_property;

        property_const_iterator found = findProperty(propertyName);
        if (found != propertyEnd())
        {
            return found->second;
        }

        return empty_property;
    }

    /// Insert a new property into the document.
    /// @return \c true if successful, \c false if already existed
    bool insertProperty(const std::string& propertyName,
                        const std::vector<std::pair<double, izenelib::util::UString> >& propertyValue)
    {
        return propertyList_.insert(
                   std::make_pair(propertyName, propertyValue)
               ).second;
    }

    /// Set a new value to a property of the document.
    void updateProperty(const std::string& propertyName,
                        std::vector<std::pair<double, izenelib::util::UString> > propertyValue)
    {
        propertyList_[propertyName].swap(propertyValue);
    }

    /// Remove a property from the document. Return false if the property
    /// can not be removed.
    /// @return true if successful, false otherwise
    bool eraseProperty(const std::string& propertyName)
    {
        return propertyList_.erase(propertyName);
    }

    property_iterator findProperty(const std::string& propertyName)
    {
        return propertyList_.find(propertyName);
    }
    property_const_iterator findProperty(const std::string& propertyName) const
    {
        return propertyList_.find(propertyName);
    }

    bool hasProperty(const std::string& pname) const
    {
        return findProperty(pname) != propertyEnd();
    }

    property_iterator propertyBegin()
    {
        return propertyList_.begin();
    }
    property_iterator propertyEnd()
    {
        return propertyList_.end();
    }
    property_const_iterator propertyBegin() const
    {
        return propertyList_.begin();
    }
    property_const_iterator propertyEnd() const
    {
        return propertyList_.end();
    }

    void clear()
    {
        propertyList_.clear();
    }

    bool isEmpty()
    {
        return propertyList_.empty();
    }

    void swap(Summarization& rhs)
    {
        propertyList_.swap(rhs.propertyList_);
        fingerPrint_.swap(rhs.fingerPrint_);
    }

    size_t getPropertySize() const
    {
        return propertyList_.size();
    }

    bool operator==(const Summarization & x) const
    {
        return fingerPrint_ == x.fingerPrint_;
    }

    bool operator!=(const Summarization & x) const
    {
        return fingerPrint_ != x.fingerPrint_;
    }

private:
    /// list of doc ids this summarization is built based on
    fingerprint_type fingerPrint_;

    /// list of properties of the document
    property_named_map propertyList_;

    template<class DataIO>
    friend void DataIO_loadObject(DataIO& dio, Summarization& x);
    template<class DataIO>
    friend void DataIO_saveObject(DataIO& dio, const Summarization& x);

public:
    MSGPACK_DEFINE(fingerPrint_, propertyList_);
};

inline void swap(Summarization& a, Summarization& b)
{
    a.swap(b);
}

template<class DataIO>
inline void DataIO_loadObject(DataIO& dio, Summarization& x)
{
    dio & x.fingerPrint_;
    dio & x.propertyList_;
}
template<class DataIO>
inline void DataIO_saveObject(DataIO& dio, const Summarization& x)
{
    dio & x.fingerPrint_;
    dio & x.propertyList_;
}

} // namespace sf1r

MAKE_FEBIRD_SERIALIZATION( sf1r::Summarization )

#endif // SF1R_MINING_MANAGER_SUMMARIZATION_SUBMANAGER_SUMMARIZATION_H
