#pragma once
#include <vector>

enum class Comand;

/// @class
/// @brief класс наблюдатель
template <typename T>
class Observer {
 public:
  virtual void UpDate(T) = 0;
};

/// @class
/// @brief класс наблюдаемый
template <typename T>
class Observered {
 public:
  /// добавить наблюдателя
  void AddObserver(Observer<T>* observer);
  /// уведомить наблюдателей
  void NotifyUpdate(T comand);

 private:
  /// наблюдатели
  std::vector<Observer<T>*> observers_;
};

template <typename T>
void Observered<T>::AddObserver(Observer<T>* observer) {
  observers_.push_back(observer);
}

template <typename T>
void Observered<T>::NotifyUpdate(T comand) {
  for (Observer<T>* observer : observers_) {
    if (observer) {
      observer->UpDate(comand);
    }
  }
}
