#include "SoundManager.hh"

using namespace Gui;
using namespace Audio;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void		SoundManager::loadSound(const std::string &filepath, const std::string &key)
{
  sf::SoundBuffer *buffer = new sf::SoundBuffer;
  if (!buffer->loadFromFile(filepath))
    {
      std::cerr << "Sound \"" << key << "\" not found." << std::endl;
      return;
    }
  _soundsMemory[key] = buffer;
}

void		SoundManager::playSound(const std::string &key, int volume)
{
  auto i = _soundsMemory.find(key);
  
  if (i != _soundsMemory.end())
    {
      sf::Sound *sound = new sf::Sound;
      
      sound->setBuffer(*_soundsMemory[key]);
      sound->setVolume(volume);
      sound->play();
      _currentSounds.push_back(sound);
    }
}

void		SoundManager::playMusic(const std::string &key, int volume)
{
  if (_musicName == key)
    return;
  stopMusic();
  _musicName = "";
  auto i = _soundsMemory.find(key);
  
  if (i != _soundsMemory.end())
    {
      sf::Sound *temp = new sf::Sound;

      temp->setBuffer(*_soundsMemory[key]);
      temp->setVolume(volume);
      temp->play();
      temp->setLoop(true);
      _music = temp;
      _musicName = key;
    }
}

void		SoundManager::stopMusic()
{
  if (_music != NULL)
    {
      _music->stop();
      delete _music;
      _music = NULL;
    }
}

void		SoundManager::clearCurrentSounds()
{
  for (auto elem = _currentSounds.begin(); elem != _currentSounds.end(); elem++)
    {
      if ((*elem)->getStatus() == sf::SoundSource::Stopped)
	{
	  delete *elem;
	  elem = _currentSounds.erase(elem);
	}
    }
}
