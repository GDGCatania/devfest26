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

## Preparazione facoltativa

Se C++, Python e Go sono già pronti, puoi passare direttamente alle sfide.

`doctor` e `setup` sono aiuti facoltativi per preparare l'ambiente, mentre
la verifica completa delle soluzioni è necessaria per il premio. Esempio:

```sh
./bin/macos-arm64/check doctor
./bin/macos-arm64/check setup --dry-run
./bin/macos-arm64/check setup
```

`doctor` controlla che C++17, Python 3.12+ e Go 1.26+ siano disponibili e funzionanti. Non esegue le soluzioni e non installa nulla. Il messaggio
`READY: all toolchain probes passed.` riguarda soltanto l'ambiente, non il premio.

Se serve, `setup` può installare gli strumenti necessari: richiede Internet
e una conferma interattiva tramite `y` o `yes`, e premere Invio significa **no**.

Con `--dry-run` puoi vedere la lista senza installare nulla. Dopo la preparazione dell'ambiente puoi verificare le soluzioni anche offline.

Il setup automatico richiede Homebrew e la toolchain Apple su macOS, oppure
winget su Windows x64. Su Ubuntu 24.04+ o Debian 13+ per AMD64/ARM64 usa apt,
con pacchetti ufficiali sufficientemente recenti. Windows ARM64 e gli altri
sistemi richiedono la preparazione manuale.

**Non c'è una garanzia universale di funzionamento per `setup`**. 

Per controllare una sola prova, basta usare ad esempio `./bin/macos-arm64/check amnesia`.

L'opzione `--help` mostra l'uso completo.

## Setup manuale su Windows

Su Windows x64 scarica ed estrai l'archivio di un compilatore C++17 MinGW-w64
completo, ad esempio [WinLibs](https://winlibs.com/), con header, linker e runtime.

LLVM o MSVC da soli non bastano per questo checker. Installa anche
[Python 3.12+](https://www.python.org/downloads/windows/) e
[Go 1.26+](https://go.dev/dl/) dalle distribuzioni ufficiali.

Rendi gli strumenti raggiungibili nel `PATH`, aggiungendo per MinGW la cartella `bin`. Riapri PowerShell nella root del progetto ed esegui `doctor` con il binario scelto dalla tabella.

## Mostra il risultato allo staff

Esegui il checker originale **senza selezionare una prova** e mostra allo staff tutti i 48 check superati. Il risultato deve riportare `pause: 10/10`, `squeeze: 13/13`, `amnesia: 15/15` e `paperclips: 10/10`, seguiti da `PASS: all selected cases passed.`.

```sh
./bin/macos-arm64/check
```

L'ultima riga deve essere questa:

> Head over to the GDG Catania staff and collect your prize.
