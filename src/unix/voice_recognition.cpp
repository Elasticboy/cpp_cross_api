#include "core/platform_config.h"

#if defined(UNIX_PLATFORM)

#include "../voice_recognition.h"

namespace voice_recognition
{
	bool is_implemented() { return false; }

    recognizer::recognizer() { }

    recognizer::~recognizer() { }

    void recognizer::add_vocal_command()
    {
        // TODO: Implement recognizer::add_vocal_command()
    }

    void recognizer::start_listening(const std::string& keyword)
    {
        // TODO: Implement recognizer::start_listening(const std::string& keyword)
    }
}

#endif
