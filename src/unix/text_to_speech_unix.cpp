#include "platform_config.h"
#if defined(UNIX_PLATFORM)

#include "../text_to_speech.h"

#include <vector>

namespace text_to_speech
{

    std::vector<std::string> available_languages()
    {
        // TODO: Find a way to implement text_to_speech::available_languages()
        return std::vector<std::string>();
    }

    bool testParameters(const std::string& language, const std::string& gender)
    {
        // TODO: Implement text_to_speech::testParameters() for Linux
        return false;
    }

    bool say(const std::string& textToSpeak, const std::string& language, const std::string& gender)
    {
        // TODO: Implement text_to_speech::say() for Linux
        return false;
    }

}

#endif
