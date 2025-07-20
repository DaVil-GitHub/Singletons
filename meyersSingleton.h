/**
 * @version 1.0
 * @date    2025/07/20
 * 
 * Classical implementation of the Meyers Singleton.
 * Thread safety limited only to defined behavior of accessing static variables.
 * Make sure to declare MeyersSingleton<t_singletonClass> as a friend of class t_singletonClass. 
 */

#pragma once

template<typename t_singletonClass>
class MeyersSingleton
{
protected:
  //SINGLETON
      //Delete copy and move options
  MeyersSingleton(const MeyersSingleton&) = delete;
  MeyersSingleton(const MeyersSingleton&&) = delete;
  MeyersSingleton& operator=(MeyersSingleton&) = delete;
  MeyersSingleton& operator=(MeyersSingleton&&) = delete;
  
  //DATA
      //None, it's a Meyers Singleton
  //CONSTRUCTORS
  MeyersSingleton() = default;
  ~MeyersSingleton() = default;
  //ACCESSORS
  inline static t_singletonClass& getInstance()
  { 
    static t_singletonClass instance;
    return instance;
  }
  //MANIPULATORS
};