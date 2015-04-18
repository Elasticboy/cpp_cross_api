#pragma once

namespace voice_recognition
{
    /** @return True if voice recognition is implemented for the current platform. */
    bool is_implemented();

    class recognizer
    {
    public:
        recognizer();
        ~recognizer();

        void add_vocal_command();
        void start_listening(const std::string& keyword);

    private:
        std::string key_word_;
    };

    // TODO: move in a more global scope (can be use for all listeners) => move in executor ?
    class action { };

    //void listen_to(const std::string& key_word, const std::string& sentence, bool (*action)());
    // TODO: Create a VoiceRecognitionEntity
    // TODO: Create an VocalCommand that could be associate to an action (callback)
    // TODO: externalize UremoteServer VoiceListener stuffs here
}

