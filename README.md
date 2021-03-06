### Задача
Решаем на языках `c++` и `prolog` следующую задачу:  
Имеется кватратная решетка 5х5.  
![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7Cc%7Cc%7Cc%7Cc%7C%7D%20%5Chline%20%26%20%26%20%26%20%26%20%5C%5C%20%5Chline%20%26%20%26%20%26%20%26%20%5C%5C%20%5Chline%20%26%20%26%20%26%20%26%20%5C%5C%20%5Chline%20%26%20%26%20%26%20%26%20%5C%5C%20%5Chline%20%26%20%26%20%26%20%26%20%5C%5C%20%5Chline%20%5Cend%7B%7D)  

И мы хотим в ее ячейках расставить наклонные линии так, чтобы их концы нигде соединялись. Т.е. чтобы в сетке не получились следующие ситуации:  

![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7Cc%7C%7D%20%5Chline%20%5Cdiagup%20%26%20%5Cdiagdown%20%5C%5C%20%5Chline%20%5Cend%7B%7D) &nbsp; &nbsp; &nbsp; &nbsp; ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7Cc%7C%7D%20%5Chline%20%5Cdiagdown%20%26%20%5Cdiagup%20%5C%5C%20%5Chline%20%5Cend%7B%7D)
&nbsp; &nbsp; &nbsp; &nbsp; ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7C%7D%20%5Chline%20%5Cdiagdown%20%5C%5C%20%5Chline%20%5Cdiagup%20%5C%5C%20%5Chline%20%5Cend%7B%7D)
&nbsp; &nbsp; &nbsp; &nbsp; ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7C%7D%20%5Chline%20%5Cdiagup%20%5C%5C%20%5Chline%20%5Cdiagdown%20%5C%5C%20%5Chline%20%5Cend%7B%7D)
&nbsp; &nbsp; &nbsp; &nbsp; ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7Cc%7C%7D%20%5Chline%20%5Cdiagdown%20%26%20%5C%5C%20%5Chline%20%26%20%5Cdiagdown%20%5C%5C%20%5Chline%20%5Cend%7B%7D)
&nbsp; &nbsp; &nbsp; &nbsp; ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Barray%7D%7B%7Cc%7Cc%7C%7D%20%5Chline%20%26%20%5Cdiagup%20%5C%5C%20%5Chline%20%5Cdiagup%20%26%20%5C%5C%20%5Chline%20%5Cend%7B%7D)  

И хочется узнать наибольшее количество наклонных линий, которой можно в такую решетку раставить.
Решение, очевидно, должно предоставить пример их расставления и сказать, что большее количество уже не влезет.

### Решение на `c++`
В решении заведена переменная `NUM`  .  
Реализация на `c++` поочередно заполняет ячейки возможными символами, т.е. левой палочкой, правой, или пустотой. Когда вся решетка заполнена если количестко палочек совпало с `NUM`, то решение печатается. Если запускать программу для разных `NUM`, увидим, что максимальный возможный `NUM`, когда решение есть - это 16.

### Решение на `prolog`
Ссылка на онлайн редактор и компилятор: https://swish.swi-prolog.org/  
В программе заданы все возможные пары соседства. (т.е. все пары, кроме перечисленных в постановке задачи, как запрещенные).  
Программа получает желаемое количество палочек и список из 25 переменных. И выводит все возможные наборы этих переменных (т.е. заполненную решетку) с нужным количеством в ней палочек. Аналогично, запуская для разного их количества, получаем ответ - 16.  
Запустить так (в левом нижнем окне):  `possible_table(15, A11, A12, A13, A14, A15, A21, A22, A23, A24, A25, A31, A32, A33, A34, A35, A41, A42, A43, A44, A45, A51, A52, A53, A54, A55).`

