/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include "Logger.h"

#include <QObject>

namespace nc {

std::string LogLevel::getName(Level level) {
    switch (level) {
        case DEBUG:
            return "Debug";
        case INFO:
            return "Info";
        case WARNING:
            return "Warning";
        case ERROR:
            return "Error";
    }
    return std::string();
}

} // namespace nc

/* vim:set et sts=4 sw=4: */
