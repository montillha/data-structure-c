# 📑 Fila de Banco 

Este projeto simula o sistema de atendimento de um banco, com duas filas: uma para clientes **preferenciais** e outra para o **público geral**.

## 📌 Regras de Atendimento:
- Se a **fila de prioridades** estiver **vazia**, chama-se o próximo cliente da **fila geral**.
- Se houver clientes na **fila de prioridades**:
  - Podem ser chamados **até 3 clientes preferenciais consecutivos**.
  - Após isso, é obrigatório chamar um cliente da **fila geral**, antes de retornar para os preferenciais.

---

## 📥 Comandos (Entrada):

- `p <nome>` → Adiciona um cliente preferencial à fila.
- `g <nome>` → Adiciona um cliente geral à fila.
- `s` → Realiza um atendimento, chamando um cliente de acordo com as regras.
- `f` → Encerra o expediente e imprime a ordem completa de atendimento.

