# Specifiche delle prove

Le prove leggono da stdin e scrivono su stdout, in JSON per Python e Go, e in semplice formato testo per C++.

Usa solo librerie standard, non c'è bisogno di aggiungere messaggi e mantieni invariati nomi, firme e formati.

## amnesia.py

Una cache ha una memoria limitata e, quando è piena, dimentica l'elemento usato meno di recente.

`amnesia.py` riceve un JSON con `capacity`, un intero da 0 a 100, e `operations`, che contiene da 0 a 1000 operazioni nel formato `["put", key, value]` oppure `["get", key]`. Le chiavi sono stringhe e i valori sono interi da -1000000 a 1000000, incluso zero.

Un `put` inserisce o aggiorna il valore. Ogni `put` e ogni `get` riuscito rendono la chiave la più recente. Una nuova chiave oltre capacità espelle quella usata meno di recente, mentre aggiornare una chiave esistente non ne espelle altre. Con capacità zero non memorizzare nulla.

Restituisci la lista dei risultati dei soli `get`, usando `null` per le chiavi assenti. Una lettura fallita non modifica l'ordine d'uso. Se non ci sono `get`, restituisci `[]`.

Per esempio, questo input restituisce `[0,null,0]`:

```json
{"capacity":2,"operations":[
  ["put","a",0],["put","b",2],["get","a"],
  ["put","c",3],["get","b"],["get","a"]
]}
```

## paperclips.go

Gestisci una piccola fabbrica comprando filo, producendo graffette e vendendole.

In `paperclips/paperclips.go` modifica solo il corpo di `simulate`, lasciando invariati tipi, firme, import e `main`. Il JSON contiene il denaro iniziale `money`, il filo iniziale `wire` e una lista `operations` di massimo 1000 azioni, anche vuota.

Ogni azione ha un `kind` tra `"buy"`, `"make"` e `"sell"` e una `quantity`.
Denaro iniziale, filo iniziale e quantità sono interi da 0 a 1000000. Le graffette iniziali sono zero.

Esegui le azioni nell'ordine dato. `buy` spende un'unità di denaro per ogni unità di filo. `make` consuma un'unità di filo per produrre una graffetta e `sell` vende ogni graffetta per due unità di denaro, togliendola dall'inventario.

Se le risorse non bastano per tutta l'azione, ignorala senza cambiare nulla.
Una quantità zero non cambia lo stato.

Restituisci un oggetto JSON con i valori interi finali di `money`, `wire` e `clips`.

Per esempio, questo input restituisce `{"money":4,"wire":1,"clips":1}`:

```json
{"money":5,"wire":0,"operations":[
  {"kind":"buy","quantity":3},
  {"kind":"make","quantity":2},
  {"kind":"sell","quantity":1}
]}
```

## pause.cpp

Trova gli spazi liberi di un'agenda a partire dagli intervalli già prenotati.

`pause.cpp` legge `duration count` sulla prima riga, poi `count` righe nel formato `start end`. Sono tutti interi, con `duration` da 1 a 1000000, `count` da 0 a 100 e tempi da -1000000 a 2000000, dove `start <= end`. Gli intervalli includono l'inizio ed escludono la fine.

Le prenotazioni possono essere disordinate, sovrapposte, annidate o esterne.
Ritagliale a `[0, duration)` e ignora gli intervalli vuoti. Stampa gli intervalli liberi massimali come `start end`, uno per riga, in ordine crescente e senza intervalli vuoti. Se non ce ne sono, stampa soltanto `-`.

Con il seguente input il risultato è `0 1`:

```text
10 2
1 6
4 10
```

## squeeze.cpp

Trova il tratto di eventi più lungo che rispetta un limite di categorie e un budget.

`squeeze.cpp` legge `count limit budget`, poi `count` righe nel formato `category cost`. Sono tutti interi, con `count` da 0 a 1000, `limit` da 0 a 100 e `budget` da 0 a 1000000000000.

Le categorie vanno da -1000000 a 1000000 e i costi vanno da 0 a 1000000000.
Ogni occorrenza contribuisce al totale, che può superare i 32 bit.

Trova la finestra contigua più lunga con al massimo `limit` categorie distinte e costo totale non superiore a `budget`. A parità di lunghezza scegli il costo minore, poi lo `start` minore. Stampa gli indici `start end`, a partire da zero, per l'intervallo `[start, end)`. Se nessuna finestra non vuota è valida, stampa `0 0`.

Con questo input il risultato è `1 3`:

```text
3 1 3
1 2
2 1
2 2
```
