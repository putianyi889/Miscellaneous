# Highlighted Julia Code Block in LaTeX

`minted` package needs specific python configuration. Too tedious and I wasn't able to get it work on my machine, probably because I use `pyenv` to manage multiple versions at once.

`jlcode` is what I'm using at present. It uses `listings` under the hood, with customized Julia keywords and colors. It is an sty file that needs to be copy-pasted into the working directory. It has a bug, causing conflicts with general listing formatting. Otherwise it's easy to work with.
