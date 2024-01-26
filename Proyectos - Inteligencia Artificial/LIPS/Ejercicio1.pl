%Katerine_Lisbeth_Rafael_Bourdierd_2022_0088

%Hechos 
es_guitarrista(paco_de_Lucia).
es_cientifico(john_McCarthy).
es_musico1(string).
es_quimico(friedman).
es_artista(beethoven).

%Reglas_del_ejercicio
%Regla1
animales(A):-esmamiferos(A).
%Regla2
esmamiferos(A):-humanos(A).
%Regla3
humanos(A):-es_cientifico(A);artistas(A).
%Regla4
es_musico(A):-artistas(A).
%Regla5
esguitarrista(A):-es_musico1(A).
%Regla6
esquimico(A):-es_cientifico(A).
artistas(A):-es_guitarrista(A).



















