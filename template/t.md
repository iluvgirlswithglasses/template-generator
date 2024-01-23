---
title: "Cooking a Bomb"
author: "iluvgirlswithglasses"
date: "{{mdtime}}"

geometry: margin=2cm
fontsize: 12pt
urlcolor: blue
---

\tableofcontents

\listoffigures

\listoftables

\pagebreak

Mostly compiled with:

```sh
pandoc \
	-o o.pdf \
	-M link-citations=true \
	--pdf-engine xelatex \
	--number-sections \
	--citeproc \
	--bibliography references.bib \
	header.md \
	introduction.md \
	references.md
```

Include this in yaml if you write an abstract:

```yaml
header-includes:
    - \usepackage{setspace}
    - \let\oldmaketitle\maketitle
    - \renewcommand{\maketitle}{\oldmaketitle\vspace{4em}}
```

