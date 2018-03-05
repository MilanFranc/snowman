/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include "Symbol.h"

#include <QObject>

#include <nc/common/Unreachable.h>

namespace nc {
namespace core {
namespace image {

std::string SymbolType::getName(Type type) {
    switch (type) {
        case NOTYPE:
            return "None";
        case FUNCTION:
            return "Function";
        case OBJECT:
            return "Object";
        case SECTION:
            return "Section";
    }
    unreachable();
}

} // namespace image
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
