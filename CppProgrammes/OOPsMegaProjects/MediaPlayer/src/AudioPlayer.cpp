#include "AudioPlayer.h"
#include <iostream>
#include <vector>

AudioPlayer::AudioPlayer() {
    mpg123_init();
    device = alcOpenDevice(nullptr);
    context = alcCreateContext(device, nullptr);
    alcMakeContextCurrent(context);
    alGenSources(1, &source);
    alGenBuffers(1, &buffer);
}

AudioPlayer::~AudioPlayer() {
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
    mpg123_exit();
}

bool AudioPlayer::loadMP3(const std::string& filename) {
    mpg123_handle *mh = mpg123_new(nullptr, nullptr);
    mpg123_open(mh, filename.c_str());

    long rate;
    int channels, encoding;
    mpg123_getformat(mh, &rate, &channels, &encoding);

    std::vector<unsigned char> audioData;
    unsigned char buffer[4096];
    size_t done;

    while (mpg123_read(mh, buffer, sizeof(buffer), &done) == MPG123_OK) {
        audioData.insert(audioData.end(), buffer, buffer + done);
    }

    ALenum format = (channels == 2) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16;

    alBufferData(this->buffer, format, audioData.data(), audioData.size(), rate);
    alSourcei(this->source, AL_BUFFER, this->buffer);

    mpg123_close(mh);
    mpg123_delete(mh);
    return true;
}

void AudioPlayer::play() {
    alSourcePlay(source);
}

void AudioPlayer::stop() {
    alSourceStop(source);
}

void AudioPlayer::setVolume(float volume) {
    alSourcef(source, AL_GAIN, volume);
}
