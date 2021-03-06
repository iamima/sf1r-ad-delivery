/**
 * @file    PropertyConfig.h
 * @brief   Defines & implements PropertyConfig class
 * @author  MyungHyun Lee (Kent)
 * @date    2008-10-15
 */

#ifndef _SF1V5_PROPERTY_CONFIG_H_
#define _SF1V5_PROPERTY_CONFIG_H_

#include <common/type_defs.h>
#include <la-manager/AnalysisInformation.h>

#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>

#include <stdint.h>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

namespace sf1r
{

/**
 * @brief This class is the class that contains the actual configuration data for each property.
 *
 */
struct PropertyConfigBase
{
    PropertyConfigBase()
        : propertyId_(0)
        , propertyType_(sf1r::UNKNOWN_DATA_PROPERTY_TYPE)
    {}

    /**
     * @brief Internal id set by configuration manager (Used in IndexManager)
     *
     * @details
     * The ID is given sequentially by the order the property is added to the document schema.
     * (Usually in the order of in the configuration file)
     */
    uint32_t propertyId_;

    /// @brief The name of this Property. The alias name.
    std::string propertyName_;

    /// @brief The data type of this property.
    sf1r::PropertyDataType propertyType_;
};

class PropertyConfig: public PropertyConfigBase
{
public:
    //------------------------  CONSTRUCTORS  ------------------------

    /**
     * @brief   Initializes the member variables with default values
     */
    PropertyConfig()
        : displayLength_(0)
        , summaryNum_(0)
        , bIndex_(false)
        , bSuffixIndex_(false)
        , bSnippet_(false)
        , bSummary_(false)
        , bHighlight_(false)
        , bFilter_(false)
        , bMultiValue_(false)
        , bRange_(false)
        , bStoreDocLen_(false)
        , rankWeight_(0.0f)
        , brtype_(false)
    {}

    PropertyConfig(const PropertyConfigBase& base)
        : PropertyConfigBase(base)
        , displayLength_(0)
        , summaryNum_(0)
        , bIndex_(false)
        , bSuffixIndex_(false)
        , bSnippet_(false)
        , bSummary_(false)
        , bHighlight_(false)
        , bFilter_(false)
        , bMultiValue_(false)
        , bRange_(false)
        , bStoreDocLen_(false)
        , rankWeight_(0.0f)
        , brtype_(false)
    {}

public:
    //------------------------  PUBLIC MEMBER FUNCTIONS  ------------------------

    /**
     * @brief Sets field id
     *
     * @param id The id value
     */
    inline void setPropertyId(uint32_t id)
    {
        propertyId_ = id;
    }

    /**
     * @brief   Returns field id
     *
     * @return  The id value
     */
    inline uint32_t getPropertyId() const
    {
        return propertyId_;
    }



    /**
     * @brief Sets the name of the property
     *
     * @param name The name of the property
     *
     * @details
     * A "name" is the "alias" value in the configuration file.
     * When the property only has one <Indexing> config, then the "name" will be the same as "OriginalName"
     * If there are more than one <Indexing> config for the property, only one "name" will match the
     * "originalName" since the <Indexing> configs will have different "alias" names.
     */
    inline void setName(const std::string& name)
    {
        propertyName_ = name;
    }

    /**
     * @brief Returns Property name.
     *
     * @return The name of the property
     *
     * @details
     * A "name" is the "alias" value in the configuration file.
     * When the property only has one <Indexing> config, then the "name" will be the same as "OriginalName"
     * If there are more than one <Indexing> config for the property, only one "name" will match the
     * "originalName" since the <Indexing> configs will have different "alias" names.
     */
    inline const std::string& getName() const
    {
        return propertyName_;
    }



    /**
     * @brief Sets the Property's original name
     *
     * @param oriName   The original Property name
     *
     * @details
     * Original name is the property's name specified in the configuration file. However, a property may have
     * alias copies of itself by assigning multiple <Indexing> configs to a single Property.
     * The original name is to sepcify the original property setting.
     */
    inline void setOriginalName(const std::string& oriName)
    {
        originalName_ = oriName;
    }

    /**
     * @brief   Returns Property's original name.
     *
     * @return  The original name of the property
     *
     * @details
     * Original name is the property's name specified in the configuration file. However, a property may have
     * alias copies of itself by assigning multiple <Indexing> configs to a single Property.
     * The original name is to sepcify the original property setting.
     */
    inline const std::string& getOriginalName() const
    {
        return originalName_;
    }

    /**
     * @brief Set Property
     *
     * @param type  The property type as specified in document-manager
     *
     * TODO: Need to finalize the names
     */
    inline void setType(sf1r::PropertyDataType type)
    {
        propertyType_ = type;
    }

    /**
     * @brief   Return property type.
     *
     * @return  The property type as specified in document-manager
     */
    inline sf1r::PropertyDataType getType() const
    {
        return propertyType_;
    }

    inline bool isRTypeString() const
    {
        return (propertyType_ == STRING_PROPERTY_TYPE) && brtype_ && !isAnalyzed();
    }
    inline void setRType(bool rtype) 
    {
        brtype_ = rtype;
    }

    inline bool isRTypeNumeric() const
    {
        return isIndex() && !isAnalyzed() &&
            getIsFilter() && !getIsMultiValue() &&
            (isNumericType() || propertyType_ == DATETIME_PROPERTY_TYPE);
    }

    inline bool isNumericType() const
    {
        return (propertyType_ == INT32_PROPERTY_TYPE
                || propertyType_ == FLOAT_PROPERTY_TYPE
                || propertyType_ == INT8_PROPERTY_TYPE
                || propertyType_ == INT16_PROPERTY_TYPE
                || propertyType_ == INT64_PROPERTY_TYPE
                || propertyType_ == DOUBLE_PROPERTY_TYPE);
    }

    /**
     * @brief Sets a boolean value of whether ths property is  indexed or not
     *
     * @param isIndex   Flag. If true, the property is indexed.
     */
    inline void setIsIndex(const bool isIndex)
    {
        bIndex_ = isIndex;
    }

    /**
     * @brief Returns a boolean value of whether ths property is indexed or not
     *
     * @return  Flag. If true, the property is indexed.
     */
    inline bool isIndex() const
    {
        return bIndex_;
    }
    
    /**
     * @brief Sets the length of the display text of the property
     *
     * @param displayLength The length in number of characters
     */
    inline void setDisplayLength(const unsigned int displayLength)
    {
        displayLength_ = displayLength;
    }

    /**
     * @brief Gets the length of the display text of this property
     *
     * @return The length in number of characters
     */
    inline unsigned int getDisplayLength() const
    {
        return displayLength_;
    }

    /**
     * @brief Sets the number of summarized sentences to save in indexing time
     *
     * @param displayLength The number of sentences
     */
    inline void setSummaryNum(const unsigned int num)
    {
        summaryNum_ = num;
    }

    /**
     * @brief Gets the number of summarized sentences to save in indexing time
     *
     * @return  The number of sentences
     */
    inline unsigned int getSummaryNum() const
    {
        return summaryNum_;
    }

    /**
     * @brief Sets whether the property will generate snippet
     *
     * @param snippet   Flag. If true, a snippet is generated from this property
     */
    inline void setIsSnippet(const bool snippet)
    {
        bSnippet_ = snippet;
    }

    /**
     * @brief Gets whether the property will generate snippet
     *
     * @return  Flag. If true, a snippet is generated from this property
     */
    inline bool getIsSnippet() const
    {
        return bSnippet_;
    }

    /**
     * @brief Sets whether the property will generate summary
     *
     * @param summary   Flag. If true, a summary is generated from this property
     */
    inline void setIsSummary(const bool summary)
    {
        bSummary_ = summary;
    }

    /**
     * @brief Returns whether the property will generate summary
     *
     * @return  Flag. If true, a summary is generated from this property
     */
    inline bool getIsSummary() const
    {
        return bSummary_;
    }

    /**
     * @brief Sets whether the property will generate highlighting
     *
     * @param highlight     Flag. If true, the property(text, or snippet, or summary) is highlighted
     */
    inline void setIsHighlight(const bool highlight)
    {
        bHighlight_ = highlight;
    }

    /**
     * @brief Sets whether the property will generate highlighting
     *
     * @return  Flag. If true, the property(text, or snippet, or summary) is highlighted
     */
    inline bool getIsHighlight() const
    {
        return bHighlight_;
    }

    /**
     * @brief Sets whether the property will generate snippet
     *
     * @param snippet   Flag. If true, a snippet is generated from this property
     */
    inline void setIsFilter(const bool bFilter)
    {
        bFilter_ = bFilter;
    }

    /**
     * @brief Gets whether the property will generate snippet
     *
     * @return  Flag. If true, a snippet is generated from this property
     */
    inline bool getIsFilter() const
    {
        return bFilter_;
    }


    /**
    * @brief Gets whether the property is subdoc 
    */
    inline bool getIsSubDoc() const
    {
        return SUBDOC_PROPERTY_TYPE == propertyType_ ? true : false;
    }

    inline void setIsMultiValue(const bool bMultiValue)
    {
        bMultiValue_ = bMultiValue;
    }

    inline bool getIsMultiValue() const
    {
        return bMultiValue_;
    }

    inline void setIsRange(const bool bRange)
    {
        bRange_ = bRange;
    }

    inline bool getIsRange() const
    {
        return bRange_;
    }

    inline void setIsStoreDocLen(const bool bStoreDocLen)
    {
        bStoreDocLen_ = bStoreDocLen;
    }

    inline bool getIsStoreDocLen() const
    {
        return bStoreDocLen_;
    }
    /**
     * @brief Sets the AnalysisInfo of this property.
     *
     * @param analysisInfo  AnalysisInfo assigned to this property
     *
     * @details
     * AnalysisInfo consists of a LA unit, and a list of regulators.
     * They are given in <Indexing> config of a Property.
     */
    inline void setAnalysisInfo(const AnalysisInfo & analysisInfo)
    {
        analysisInfo_ = analysisInfo;
    }

    /**
     * @brief Returns the AnalysisInfo of this property.
     *
     * @return  AnalysisInfo assigned to this property
     *
     * @details
     * AnalysisInfo consists of a LA unit, and a list of regulators.
     * They are given in <Indexing> config of a Property.
     */
    inline const AnalysisInfo & getAnalysisInfo() const
    {
        return analysisInfo_;
    }

    /**
     * @brief Sets the name of this unit
     *
     * @param name  The name of this unit.
     */
    inline void setRankWeight(const float rankWeight)
    {
        rankWeight_ = rankWeight;
    }

    /**
     * @brief Gets the name of this unit
     *
     * @return  The ID of this unit
     */
    inline float getRankWeight() const
    {
        return rankWeight_;
    }

    //if the property type is 'string', and there is an analysis method for the property,
    //then inverted index would be created for the property.
    bool isAnalyzed() const;

    /**
     * @return true for alias property, otherwise, false is returned
     */
    bool isAliasProperty() const;

    std::string toString() const;

    void swap(PropertyConfig& rhs)
    {
        using std::swap;
        swap(propertyId_, rhs.propertyId_);
        swap(propertyName_, rhs.propertyName_);
        swap(propertyType_, rhs.propertyType_);
        swap(originalName_, rhs.originalName_);
        swap(bIndex_, rhs.bIndex_);
        swap(bSuffixIndex_, rhs.bSuffixIndex_);
        swap(displayLength_, rhs.displayLength_);
        swap(summaryNum_, rhs.summaryNum_);
        swap(bSnippet_, rhs.bSnippet_);
        swap(bSummary_, rhs.bSummary_);
        swap(bHighlight_, rhs.bHighlight_);
        swap(bFilter_, rhs.bFilter_);
        swap(bMultiValue_, rhs.bMultiValue_);
        swap(bRange_, rhs.bRange_);
        swap(bStoreDocLen_, rhs.bStoreDocLen_);
        swap(analysisInfo_, rhs.analysisInfo_);
        swap(rankWeight_, rhs.rankWeight_);
        swap(subProperties_,rhs.subProperties_);
        swap(brtype_, rhs.brtype_);
    }

private:

    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & propertyId_;
        ar & propertyName_;
        ar & propertyType_;
        ar & originalName_;
        ar & bIndex_;
        ar & bSuffixIndex_;
        ar & displayLength_;
        ar & summaryNum_;
        ar & bSnippet_;
        ar & bSummary_;
        ar & bHighlight_;
        ar & bFilter_;
        ar & bMultiValue_;
        ar & bRange_;
        ar & bStoreDocLen_;
        ar & analysisInfo_;
        ar & rankWeight_;
        ar & subProperties_;
        ar & brtype_;
    }

public:

    /// @brief  The original Property name.
    /// If the property is an alias of the original, the property name and original name will be different
    std::string originalName_;

    /// @brief  The displaying length of the property, in terms of number of characters.
    unsigned int displayLength_;

    /// @brief  The number of sentences to save from the output of summarization
    unsigned int summaryNum_;

    ///@brief   A flag indicating whether the Property will be indexed or not.
    bool bIndex_;
    
    ///@brief   A flag indicating whether the Property will be indexed or not in Suffix.
    bool bSuffixIndex_;

    /// @brief  A flag indicating whether the property generates snippet
    bool bSnippet_;

    /// @brief  A flag indicating whether the property generates summary
    bool bSummary_;

    /// @brief  A flag indicating whether the property generates highlighting
    bool bHighlight_;

    /// @brief  Whether filter will be applied to this property
    bool bFilter_;

    /// @brief  Whether multivalue filter will be applied to this property
    bool bMultiValue_;

    /// @brief  Whether to support range values for numeric property
    bool bRange_;

    /// @brief  Whether store doc length to this property
    bool bStoreDocLen_;

    /// @brief  Analysis info(la & regulator) of this property
    AnalysisInfo analysisInfo_;

    /// @brief  The ranking weight value assigned to this Property
    float rankWeight_;

    /// @brief If this property is virtual, it has several sub properties
    std::vector<std::string> subProperties_;

    /// @brief If this property is rtype string. rtype string can update efficient.
    bool brtype_;
};

struct PropertyComp
{
    bool operator()(const PropertyConfig & lhs, const PropertyConfig & rhs) const
    {
        //return (lhs.getName() < rhs.getName() || (lhs.getName() == rhs.getName() && lhs.getType() < rhs.getType()));
        return lhs.getName() < rhs.getName();
    }
};

struct PropertyBaseComp
{
    bool operator()(const PropertyConfigBase & lhs, const PropertyConfigBase & rhs) const
    {
        return lhs.propertyName_ < rhs.propertyName_;
    }
};

inline void swap(PropertyConfig& a, PropertyConfig& b)
{
    a.swap(b);
}

typedef std::set<PropertyConfigBase, PropertyBaseComp> DocumentSchema;

typedef std::set<PropertyConfig, PropertyComp> IndexBundleSchema;

} // namespace

#endif  //_SF1V5_PROPERTY_CONFIG_H_

// eof
