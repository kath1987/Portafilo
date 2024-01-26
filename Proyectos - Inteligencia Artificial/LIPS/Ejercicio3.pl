%Katerine_Lisbeth_Rafael_Bourdierd_2022_0088
%Los_tigres_son_carnivoros_mientras_que_las_jirafas_tienen_dos_patas.
carnivoros(tigres).
tienen_dos_patas(jirafas).

%Hay_animales_que_viven_en_los_zoologicos.
zoologicos(A):-animales(A).

%En_todos_los_zoologicos_habitan_animales.
animales(A):-zoologicos(A).

%Todos_los_mamiferos_son_animales
sonmamiferos(A):-animales(A).

%Todas_las_aves_son_animales.
animales1(A):-aves(A).

%Todos_los_carnivoros_son_mamiferos
sonmamiferos1(A):-carnivoros(A).

%Algunos_mamiferos_tienen_dos_patas
dos_patas(A):-mamiferos(A).

%Los_avestruces_y_los_pinguinos_son_aves.
aves(A):-avestruces(A);pinguinos(A).

%Los_avestruces_y_los_pinguinos_tienen_dos_patas.
dos_pata(A):-avestruces(A);pinguinos(A).

%Las_jirafas_y_los_avestruces_tienen_cuellos_largos.
cuellos_largos(A):-jirafas(A);avestruces(A).

%Todas_las_aves_excepto_los_avestruces_y_los_pinguinos_pueden_volar.
volar(A):-aves(A).
aves1(A,notvolar):-avestruces(A),pinguinos(A).

%Ningun_ave_excepto_los_pinguinos_pueden_nadar.
no_oueden_volar(A):-pinguinos(A).
