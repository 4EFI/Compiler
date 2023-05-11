
# Бинарный транслятор

## Введение

В прошлом семестре мы написали свой язык программирования ( [triple 'p'](https://github.com/4EFI/Language) ). Язык, который плюсовее плюсов, ведь это плюс плюс плюс :)) Написанный язык выполнялся на нами реализованном [процессоре](https://github.com/4EFI/CPU). В этой работе нам предстоит транслировать наш бинарный код в бинарный код архитектуры x86-64.

<p style="text-align: center"><img src=res/bin.png width="650px"/></p>

## Реализация трансляции

Для начала, давайте углубимся в структуру команд нашего процессора. Первый байт, а именно первые 5 бит отвечают за "cmd num", за номер соответствующей команды (0-31), далее следует бит "imm", бит который показывает, оперирует ли команда со значениями, следующий бит - "reg" - будет ли присутствовать регистр, последний бит "mem" показывает, будут ли производится действия с оперативной памяти. Изобразим это схематично: 

<p style="text-align: center"><img src=res/cmd.png width="300px"/></p>

После байта команды, следует байт "reg num", отвечающий за номер регистра, если бит "reg" выставлен в 1. Затем следуют 8 байт, значение типа double, если бит "imm" выставлен в 1.

<p style="text-align: center"><img src=res/full_cmd.png width="600px"/></p>