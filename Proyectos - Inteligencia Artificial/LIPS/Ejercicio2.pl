%Katerine_Lisbeth_Rafael_Bourdierd_2022_0088
%Hechos_de_la_situacion_1
es_ensayista(joaquin).
es_novelista(maria).
es_poeta(jose).
genero(el_Qijote, comedia).
genero(la_divina_comedia, drama).


%Reglas_de_la_situacion_1
miembro_del_club_litectura(A):-es_novelista(A);es_poeta(A);es_ensayista(A).
novelista(A):-escritor(A).
poeta(A):-escritor(A).
poetas(A):-ensayistas(A).
gustos(A,periodico):-es_ensayista(A).
gustos(A,genero(comedia)):-es_ensayista(A).
gustos(A,genero(drama)):-es_novelista(A).
gustos(A,genero(comedia)):-es_novelista(A).
gustos(jose,A):-gustos(maria,A).

