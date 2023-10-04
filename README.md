# OS
Programs built at the operational systems subject.

Team: Matheus Sá, Enzo Gebauer

# Objetivo da matéria
A matéria tem como objetivo entender o funcionamento de um sistema operacional desde de sua comunicação com a arquitetura do computador até a interface humano-máquina criada para que os usuários tenham uma experiência de uso mais amigável.

# Threads x Processo
Threads nada mais é que a execução de um código de um programa. Em um processo, pode ter n threads, ou seja, vários "pedaços" de códigos sendo executados. Os conceitos de multiprogramação e timesharing são fundantes para entendimento do funcionamento de como o SO é capaz de executar várias tarefas "ao mesmo tempo." 

# Atividades 
## Semáforos
Essa atividade consiste na criação de 200 threads sendo que 100 threads irá incrementar uma variável global e as outras 100 irão decrementar a mesma variável.
A utilização de semáforos tem o objetivo de gerenciar o paralelismo das threads (também chamadas de rotinas) para que no final o valor inicial da variável global
seja igual ao valor final.

## Threads com política de escalonamento e prioridade
Essa atividade consiste na elaboração de 5 threads com diferentes execuções para verificar o tempo de execução de cada thread e o funcionamento do paralelismo em C
utilizando a biblioteca pthread com o SO Linux Ubuntu 22.04
