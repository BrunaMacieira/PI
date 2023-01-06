pdflatex thesis -enable-installer -verbose
bibtex thesis -enable-installer -verbose
makeindex thesis.glo -s thesis.ist -t thesis.glg -o thesis.gls
makeindex thesis.acn -s thesis.ist -t thesis.alg -o thesis.acr
pdflatex thesis -enable-installer -verbose
pdflatex thesis -enable-installer -verbose
