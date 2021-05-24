### Задача
Ссылка на онлайн редактор и компилятор: https://swish.swi-prolog.org/

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
В программе заданы все возможные пары соседста. (т.е. все пары, кроме перечисленных в постановке задачи, как запрещенные).  
Программа получает желаемое количество палочек и список из 25 переменных. И выводит все возможные наборы этих переменных (т.е. заполненную решетку) с нужным количеством в ней палочек. Аналогично, запуская для разного их количества, получаем ответ - 16.
