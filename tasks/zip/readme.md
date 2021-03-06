# Zip

Реализуйте функцию `Zip`, аналогичную функции `zip` в языке Python.

Функция принимает на вход две последовательности, заданные парами `std::forward_list<std::string>::const_iterator`
и возвращает последовательность пар, где i-я пара состоит из i-х элементов первой и второй последовательности.
Выходная последовательность должна быть равной по длине меньшей из входных последовательностей. 

## Реализация

Технически функция возвращает некоторый объект, обладающий следующими свойствами:

- По объекту можно проитерироваться (т.е. использовать в правой части range-based for)
- Разыменование итератора по этому объекту возвращает `std::pair<const std::string&, const std::string&>`,
  где `first` - ссылка на элемент первого вектора, а `second` - на элемент второго.
- При инкременте итератор начинает указывать на следующие элементы входных последовательностей

Реализация должна быть однопроходной. Результирующие пары должны генерироваться на лету при разыменовании
итератора без предварительного накопления в памяти. Аллокация динамической памяти запрещена.
