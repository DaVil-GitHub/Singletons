/**
 * @version 1.0
 * @date    2025/07/20
 * 
 * Thread-secure singleton template allowing for controlled construction and deletion of underlying instance.
 * Thread-security is guaranteed by well-defined behavior of locking std::mutex and double checking for instance.
 * Doesn't have exception handling as of now.
 * Make sure to declare LazySingleton<t_singletonClass> as a friend of class t_singletonClass. 
 */

#pragma once

#include <mutex>

template <typename t_singleton>
class ControlledSingleton
{
protected:
  //SINGLETON
  static t_singleton* instance;
  static std::mutex mutex;
      //Remove copy and move options
  ControlledSingleton(const ControlledSingleton&) = delete;
  ControlledSingleton(const ControlledSingleton&&) = delete;
  ControlledSingleton& operator=(ControlledSingleton&) = delete;
  ControlledSingleton& operator=(ControlledSingleton&&) = delete;
  
  //DATA
      //None, it's a singleton template
  //CONSTRUCTORS
  ControlledSingleton() = default;
  ~ControlledSingleton() = default;

  //ACCESSORS
  inline static t_singleton& getInstance()
  {
    if (instance == nullptr)
      t_singleton::initInstance();
    return *instance;
  }

public:
  //MANIPULATORS
  inline static void initInstance()
  {
    //Check if instance is initialized
    if (instance != nullptr)
      return;
    //Lock mutex
    std::lock_guard<std::mutex> lock(mutex);
    //Double-check instance
    if (instance != nullptr)
      return;

    instance = new t_singleton();
  }
  inline static void deinitInstance()
  {
    if (instance == nullptr)
      return;

    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr)
      return;

    delete(instance);
    instance = nullptr;
  }
};