/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#pragma once

#include <nc/config.h>
#include <string>

#include <boost/optional.hpp>

#include <QCoreApplication>


#include <nc/common/Types.h>

namespace nc {
namespace core {
namespace image {

class Section;

/**
 * Symbol type.
 */
class SymbolType {
    Q_DECLARE_TR_FUNCTIONS(SymbolType)

public:
    /**
     * Symbol type values.
     */
    enum Type {
        NOTYPE,   ///< Not specified or unknown.
        FUNCTION, ///< Function.
        OBJECT,   ///< Data object.
        SECTION   ///< Section object.
    };

    /**
     * Constructor.
     *
     * \param type Symbol type value.
     */
    SymbolType(Type type = NOTYPE): type_(type) {}

    /**
     * \return Symbol type value.
     */
    operator Type() const { return type_; }

    /**
     * \param type Symbol type value.
     *
     * \return Name of the given symbol type.
     */
    static std::string getName(Type type);

    /**
     * \return Name of the symbol type.
     */
    std::string getName() const { return getName(type_); }

private:
    Type type_;
};

class Symbol {
private:
    SymbolType type_; ///< Type of the symbol.
    std::string name_; ///< Name of the symbol.
    boost::optional<ConstantValue> value_; ///< Value of the symbol.
    const Section *section_; ///< Section referenced by the symbol.

public:
    /**
     * Constructor.
     *
     * \param type Type of the symbol.
     * \param name Name of the symbol.
     * \param value Value of the symbol.
     * \param section Pointer to the section referenced by the symbol.
     */
    Symbol(SymbolType type, const std::string& name, const boost::optional<ConstantValue> &value, const Section *section = nullptr):
        type_(type), name_(name), value_(value), section_(section)
    {}

    /**
     * \return Type of the symbol.
     */
    SymbolType type() const { return type_; }

    /**
     * \return Name of the symbol.
     */
    std::string name() const { return name_; }

    /**
     * \return Value of the symbol.
     */
    const boost::optional<ConstantValue> &value() const { return value_; }

    /**
     * \return Pointer to the section references by the symbol. Can be nullptr.
     */
    const Section *section() const { return section_; }
};

} // namespace image
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
