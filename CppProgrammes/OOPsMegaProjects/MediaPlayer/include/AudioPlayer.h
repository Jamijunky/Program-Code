#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <mpg123.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <string>

class AudioPlayer {
public:
    AudioPlayer();
    ~AudioPlayer();

    bool loadMP3(const std::string& filename);
    void play();
    void stop();
    void setVolume(float volume);

private:
    ALuint source, buffer;
    ALCdevice* device;
    ALCcontext* context;
};

#endif // AUDIOPLAYER_H
