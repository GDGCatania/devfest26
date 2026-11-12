# Specifiche delle prove

Le prove leggono da stdin e scrivono su stdout: JSON per Python e Go, testo
per C++. Usa solo librerie standard e mantieni invariati nomi, firme e formati. Non stampare messaggi aggiuntivi su stdout.

A seguire una descrizione di ciascuna.

## amnesia.py

Una cache conserva un numero limitato di valori. Quando inserisci una nuova
chiave e non c'è più spazio, viene eliminata quella usata meno di recente.
Ogni inserimento o aggiornamento (`put`) e ogni lettura riuscita (`get`)
rendono la chiave la più recente. Aggiornare non elimina altre chiavi e una
lettura fallita non cambia l'ordine d'uso. Con capacità zero ovviamente non conserva nulla.

`amnesia.py` riceve un JSON con `capacity` e una lista `operations`.
Le operazioni sono `["put", key, value]` o `["get", key]`, con chiavi stringa. L'output è una lista con i risultati dei soli `get`: valori o `null` per le chiavi assenti, e `[]` senza letture.

Per esempio, il seguente input restituisce `[0,null,0]`:

```json
{"capacity":2,"operations":[
  ["put","a",0],["put","b",2],["get","a"],
  ["put","c",3],["get","b"],["get","a"]
]}
```

La capacità è un intero da 0 a 100. Sono ammesse da 0 a 1000 operazioni
e valori interi da $-10^{6}$ a $10^{6}$, incluso zero.

## paperclips.go

Parti con denaro e filo, senza graffette. In `paperclips/paperclips.go` modifica **solo il corpo di `simulate`**, lasciando invariati tipi, firme, import e `main`.

Le azioni seguono l'ordine dato: `buy` compra ogni unità di filo con un'unità
di denaro, `make` consuma un'unità di filo per produrre una graffetta e `sell` vende ciascuna graffetta per due unità di denaro, togliendola dall'inventario. Se mancano risorse per completare un'azione, ignorala **interamente** e lascia tutto com'è. Con quantità zero non cambia nulla.

Il JSON contiene il denaro iniziale `money`, il filo iniziale `wire` e la lista `operations`, anche vuota. Ogni azione ha un `kind` (`"buy"`, `"make"` o `"sell"`) e una `quantity`. L'oggetto JSON di output riporta gli interi finali `money`, `wire` e `clips`.

Per esempio, questo input restituisce `{"money":4,"wire":1,"clips":1}`:

```json
{"money":5,"wire":0,"operations":[
  {"kind":"buy","quantity":3},
  {"kind":"make","quantity":2},
  {"kind":"sell","quantity":1}
]}
```

Denaro iniziale, filo iniziale e quantità sono interi da 0 a $10^{6}$.
La lista contiene al massimo 1000 azioni.

## pause.cpp

L'agenda di `pause.cpp` ha durata `duration` e `count` prenotazioni.
Cerca tutti gli spazi liberi, senza spezzare uno spazio continuo.

Le prenotazioni non sono necessariamente ordinate e possono sovrapporsi,
rientrare in altre o cadere fuori orario. Gli intervalli includono l'inizio
ed escludono la fine. Considera solo la parte che rientra in `[0, duration)`
e ignora le prenotazioni vuote.

L'input inizia con la riga `duration count`, seguita da `count` righe
`start end`. L'output riporta così gli spazi liberi, uno per
riga in ordine crescente e senza intervalli vuoti. Se l'agenda è completamente occupata, l'output è soltanto `-`.

Con il seguente input il risultato è `0 1`:

```text
10 2
1 6
4 10
```

Tutti i dati sono interi! `duration` va da 1 a $10^{6}$ e `count` da 0 a 100.
I tempi vanno da $-10^{6}$ a $2 \cdot 10^{6}$, con `start <= end`.

## squeeze.cpp

Ogni evento ha una categoria e un costo. In `squeeze.cpp` cerchi la
sequenza più lunga di eventi consecutivi, senza saltarne nessuno, con al massimo `limit` categorie distinte e costo totale entro il budget `budget`.
La somma dei costi può superare il massimo rappresentabile da un intero a 32 bit.

Tra sequenze della stessa lunghezza scegli quella che costa meno.

Se anche il costo coincide, scegli quella che inizia prima.

L'input contiene `count limit budget`, poi `count` righe `category cost`.
L'output indica `start end` con indici da zero, includendo `start` ma non `end`. Senza sequenze non vuote valide, è `0 0`.

Con questo input il risultato è `1 3`:

```text
3 1 3
1 2
2 1
2 2
```

Anche qui, tutti i dati sono interi! `count` va da 0 a 1000, `limit` da 0 a 100 e `budget` da 0 a $10^{12}$. Le categorie vanno da $-10^{6}$ a $10^{6}$
e i costi da 0 a $10^{9}$.
