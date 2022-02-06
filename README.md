# Jumble letters
Jumble letters is a tool that mixes up every letter in a sentence except the first and last letters in each word

## Installation
To install Jumble letters you can choose to compile it yourself (not supported yet...) or download one of our precompiled binaries

### Precompiled binaries
Head over to the [releases](https://github.com/IsakTheHacker/jumble-letters/releases) section and download the latest binary (only for Linux at the moment). Put it somewhere you can access it later.

Mark the file as executable:
```bash
sudo chmod +x main
```

Now it's done! But you may want to make an alias for it so you don't need to write the full path whenever you want to use it. Append the following line to ~.bashrc:
```
alias jl=<path_to_jumble_letters>
```
Now you can access Jumble letters by just typing `jl <sentence>`.

## Usage
The usage of Jumble letters is very simple just type the path to the program or the alias you made earlier followed by the sentence you want to mess up, as noted here:

```bash
jl <sentence>
<path_to_jumble_letters> <sentence>
```

To make it a little more fun you could for example pipe the output of `jl` to `cowsay`:
```bash
jl <sentence> | cowsay
```
Or maybe take the output from `fortune` and piping it to `jl`, then piping it to `ponysay`:
```bash
fortune | jl | ponysay
```
