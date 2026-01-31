# Cheatsheet for creating a new package

## Create the package
```julia
julia> using PkgTemplates

julia> Template(interactive=true)("MyPackage")

(@v1.12) pkg> dev MyPackage
```

Manually create the repository `MyPackage.jl` on GitHub. It has to be completely blank. Don't forget the `.jl` in the repo name.

Publish the local `master` branch.

## Add Aqua tests (Optional)
Add the snippet to `runtests.jl`
```julia
using Aqua

@testset "Aqua" begin
	Aqua.test_all(MyPackage)
end
```

Badge
```md
[![Aqua QA](https://raw.githubusercontent.com/JuliaTesting/Aqua.jl/master/badge.svg)](https://github.com/JuliaTesting/Aqua.jl)
```

## Create the docs
```julia
julia> using DocumenterTools
julia> DocumenterTools.generate()
```

## List all docstrings in the docs
````
```@autodocs
Modules = [MyPackage]
```
````

## Add doctests (Optional)
Add the snippet to `runtests.jl`
```julia
using Documenter

DocMeta.setdocmeta!(MyPackage, :DocTestSetup, :(using MyPackage); recursive=true)

@testset "Doctest" begin
    doctest(MyPackage)
end
```
Don't forget to add `Documenter` to `Project.toml`. To skip doctest when building docs, add the kwarg `doctest = false` to `makedocs` in `make.jl`.

## Build the docs
Run `julia docs/make.jl` from terminal.

## Deploy the docs
```julia
julia> DocumenterTools.genkeys(user="myusername", repo="MyPackage.jl")
```
Then follow the instruction in the output.

Find this part in `docs/make.jl`
```julia
# Documenter can also automatically deploy documentation to gh-pages.
# See "Hosting Documentation" and deploydocs() in the Documenter manual
# for more information.
#=deploydocs(
    repo = "<repository url>"
)=#
```

Change it to
```julia
deploydocs(
    repo = "github.com/myusername/MyPackage.jl.git"
)
```

Create `Documentation.yml` as follows.
```Documentation.yml
name: Documentation

on:
  push:
    branches:
      - master # update to match your development branch (master, main, dev, trunk, ...)
    paths:
      - 'src/**'
      - 'docs/**'
      - '.github/workflows/Documentation.yml'
      - 'Project.toml'
    tags: '*'
  pull_request:
    branches:
      - master # update to match your development branch (master, main, dev, trunk, ...)
    paths:
      - 'src/**'
      - 'docs/**'
      - '.github/workflows/Documentation.yml'
      - 'Project.toml'
  workflow_dispatch:
jobs:
  build:
    permissions:
      contents: write
      statuses: write
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v6
      - uses: julia-actions/setup-julia@v2
        with:
          version: '1.12'
      - name: Install dependencies
        run: julia --project=docs/ -e 'using Pkg; Pkg.develop(PackageSpec(path=pwd())); Pkg.instantiate()'
      - name: Build and deploy
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }} # If authenticating with GitHub Actions token
          DOCUMENTER_KEY: ${{ secrets.DOCUMENTER_KEY }} # If authenticating with SSH deploy key
          GKSwstype: "100"
        run: julia --project=docs/ docs/make.jl
```

Push the above changes to GitHub, then wait for the Documentation workflow to finish. Normally, a branch `gh-pages` would appear and GitHub Pages would deploy it automatically.

Put the badges in `README.md`
```md
[![](https://img.shields.io/badge/docs-stable-blue.svg)](https://myusername.github.io/MyPackage.jl/stable)
[![](https://img.shields.io/badge/docs-dev-blue.svg)](https://myusername.github.io/MyPackage.jl/dev)
```

## Add code coverage test

Log into the CodeCov website with GitHub account. Find the package repository and config. Follow the instructions.
