# The Small Programming Book
A small book written by me (that is still in development).

I like to read about and implement niche data structures and obscure algorithms but since I
couldn't find just one source for all different kinds of them with the appropriate Mathematics
to back them up, I decided to author my own _book_ that contained all this information.

The book is a collection of, mostly, Jupyter Notebook since I like Python but some of the more
low level concepts are written using C++ in the form of code embdedded in Markdown documents with
the appropriate (read: full) source code in their own directories.

The final book will be a PDF of all the notebooks and Markdown files.

## Installation

To get the latest copy of the Notebooks and PDFs, clone this repository, install the Python requirements and run `jupyter notebook` in the root directory. This is hihgly recommended since GitHub does not render Jupyter's LaTeX nicely and has a lot of errors that aren't faced during development.

```sh
$ git clone https://github.com/mentix02/TheSmallProgrammingBook
$ cd TheSmallProgrammingBook
$ pip install -r requirements.txt
$ jupyter notebook
```
