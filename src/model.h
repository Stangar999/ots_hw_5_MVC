#pragma once
#include <memory>
#include <vector>

/// @class
/// @brief класс интерфейс доступных действий
class IModel {
 public:
  virtual void CreateNewDocument() = 0;
  virtual void ImportDocument() = 0;
  virtual void ExportDocument() = 0;
  virtual void CreateGraphicPrimitive() = 0;
  virtual void RemoveGraphicPrimitive() = 0;
};

namespace detail {
/// @class
/// @brief базовый класс фигур
class Figure {};

class Line : Figure {};

class Rectangle : Figure {};

class Point : Figure {};

class Spline : Figure {};

/// @class
/// @brief структура фигур расположенных на одном документе
struct Document {
  std::vector<Figure*> figures_;
};

/// @class
/// @brief класс доменной модели
///
/// толстая модель реализующая основную логику
class Model : public IModel {
 public:
  void CreateNewDocument() override;
  void ImportDocument() override;
  void ExportDocument() override;
  void CreateGraphicPrimitive() override;
  void RemoveGraphicPrimitive() override;

 private:
  std::vector<Figure*> figures_;
  /// существующие документы
  std::vector<Document> documents_;
};

}  // namespace detail
