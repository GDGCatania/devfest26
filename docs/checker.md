# Checker: guida rapida

Il checker esegue i quattro sorgenti su 48 casi predefiniti e confronta i risultati con quelli attesi. Compila C++ e Go ed esegue Python direttamente. Per ogni prova mostra quanti casi sono passati e segnala eventuali problemi, *senza* modificare o correggere i sorgenti.

Apri il terminale nella **root del progetto** e scegli il binario già incluso per il tuo computer.

| Sistema | Binario dalla root |
|---|---|
| macOS Apple Silicon | `./bin/macos-arm64/check` |
| macOS Intel | `./bin/macos-amd64/check` |
| Linux ARM64 | `./bin/linux-arm64/check` |
| Linux AMD64/x86_64 | `./bin/linux-amd64/check` |
| Windows ARM64 | `.\bin\windows-arm64\check.exe` |
| Windows x64/AMD64 | `.\bin\windows-amd64\check.exe` |

Per le sfide, servono C++17 o superiore, Python 3.12+ e Go 1.26+.

## Un Check opzionale

Non solo verifica che le soluzioni siano quelle attese, ma se hai difficoltà nel configurarti un ambiente adeguato e necessario alla challenge, ti aiuta ad impostarlo. In ogni caso, **non** è obbligatorio utilizzarli, l'importante è che tu possa procedere con le sfide.

```sh
./bin/macos-arm64/check doctor
./bin/macos-arm64/check setup --dry-run
./bin/macos-arm64/check setup
./bin/macos-arm64/check
```

`doctor` verifica che esistino C++17, Python 3.12+ e Go 1.26+, non esegue le soluzioni e soprattutto non installa nulla. Il messaggio `READY: all toolchain probes passed.` indica che l'ambiente è pronto e puoi iniziare le sfide

Se serve, `setup` può installare gli strumenti necessari (richiede Internet!) e conferma interattiva tramite `y` o `yes`. Premere Invio significa **no**. 

Con `--dry-run` puoi vedere la lista senza installare nulla. Dopo la preparazione dell'ambiente puoi verificare le soluzioni anche offline.

Il setup automatico richiede Homebrew e la toolchain Apple su macOS, oppure winget su Windows x64. Su Ubuntu/Debian per AMD64/ARM64 usa apt e richiede pacchetti ufficiali.

**Non c'è una garanzia universale di funzionamento per `setup`**. 

Anche solo per controllare solo una prova, basta usare `./bin/macos-arm64/check amnesia`.

L'opzione `--help` mostra l'uso completo.

## Mostra il risultato allo staff

Esegui il checker originale **senza selezionare una prova** e mostra allo staff tutti i 48 check superati. Il risultato deve riportare `pause: 10/10`, `squeeze: 13/13`, `amnesia: 15/15` e `paperclips: 10/10`, seguiti da `PASS: all selected cases passed.`.

L'ultima riga deve essere questa:

> Head over to the GDG Catania staff and collect your prize.
