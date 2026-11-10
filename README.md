# DevFest Catania 2026

Ciao! Benvenuto alla code challenge della DevFest Catania 2026!

Questa sfida ti porterà ad esaminare attentamente 4 file con codice da fixare.

| File e specifica | Linguaggio | |
|---|---|---|
| [`pause.cpp`](docs/challenges.md#pausecpp) | C++ |
| [`squeeze.cpp`](docs/challenges.md#squeezecpp) | C++ |
| [`amnesia.py`](docs/challenges.md#amnesiapy) | Python |
| [`paperclips/paperclips.go`](docs/challenges.md#paperclipsgo) | Go |

## Regole

Regole? Puoi fare quello che vuoi per risolvere i problemi. Usare l'AI, farti aiutare da altri partecipanti, chiedere ai tuoi amici... alla fine ciò che conta è divertirsi!

Tuttavia, tieni a mente che tutte e quattro le prove sono obbligatorie: il premio richiede **48 check su 48**. Non ci sono punteggi o premi parziali. Basta un check non superato o una verifica incompleta per non avere il premio.

Ah, ovviamente hai tempo fino alla fine della durata della DevFest. 

## Come partecipare?

Clona questo repository o scaricane il `.zip`, poi modifica soltanto i quattro sorgenti delle prove, esegui il binario **check** contenuto in `/bin` e mostra il risultato completo allo staff.

## Checker!

Sono già inclusi sei binari in `bin/` per gli OS macOS/Linux/Windows, comprese le architetture ARM64/AMD64. Si è liberi di usare Docker, Podman, una macchina virtuale o qualsiasi altra cosa per eseguire i propri test e anche il binario.

Dalla **root del progetto**, ad esempio su macOS ARM64:

```sh
./bin/macos-arm64/check doctor
./bin/macos-arm64/check setup --dry-run
./bin/macos-arm64/check setup
./bin/macos-arm64/check
```

Per tutte le informazioni sul checker, ti invitiamo a leggere la [guida, altre build e limiti](docs/checker.md).

Ricorda, un `PASS` per una singola prova non basta per ottenere il premio.

Quando hai finito, e il checker ti dà il via, mostra allo staff i quattro contatori completi (apparirà la frase `PASS: all selected cases passed.`). L'ultima riga deve essere:

> Head over to the GDG Catania staff and collect your prize.
