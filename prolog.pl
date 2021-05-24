row_neighbours(n, n).
row_neighbours(n, l).
row_neighbours(n, r).
row_neighbours(r, n).
row_neighbours(l, n).
row_neighbours(l, l).
row_neighbours(r, r).

left_dia_neighbours(n, n).
left_dia_neighbours(n, l).
left_dia_neighbours(n, r).
left_dia_neighbours(l, n).
left_dia_neighbours(r, n).
left_dia_neighbours(r, r).
left_dia_neighbours(r, l).
left_dia_neighbours(l, r).

right_dia_neighbours(n, n).
right_dia_neighbours(n, l).
right_dia_neighbours(n, r).
right_dia_neighbours(l, n).
right_dia_neighbours(r, n).
right_dia_neighbours(l, l).
right_dia_neighbours(r, l).
right_dia_neighbours(l, r).

row(A, B, C, D, E) :-
    row_neighbours(A, B),
    row_neighbours(B, C),
    row_neighbours(C, D),
    row_neighbours(D, E).

two_rows(A1, B1, C1, D1, E1, A2, B2, C2, D2, E2) :-
    row(A1, B1, C1, D1, E1),
    row(A2, B2, C2, D2, E2),
    
    row_neighbours(A1,A2),
    row_neighbours(B1,B2),
    row_neighbours(C1,C2),
    row_neighbours(D1,D2),
    row_neighbours(E1,E2),
    
    left_dia_neighbours(A1,B2),
    left_dia_neighbours(B1,C2),
    left_dia_neighbours(C1,D2),
    left_dia_neighbours(D1,E2),
    
    right_dia_neighbours(E1,D2),
    right_dia_neighbours(D1,C2),
    right_dia_neighbours(C1,B2),
    right_dia_neighbours(B1,A2).

to_int(l, I) :- I is 1.
to_int(r, I) :- I is 1.
to_int(n, I) :- I is 0.

possible_table(N, A11, A12, A13, A14, A15, A21, A22, A23, A24, A25, A31, A32, A33, A34, A35, A41, A42, A43, A44, A45, A51, A52, A53, A54, A55) :-
    COUNT0 is 0,
    COUNT0 =< N,
    
    to_int(A11, I11), to_int(A12, I12), to_int(A13, I13), to_int(A14, I14), to_int(A15, I15),
    COUNT1 is COUNT0+I11+I12+I13+I14+I15,
    COUNT1 =< N,
    row(A11, A12, A13, A14, A15),
    
    to_int(A21, I21), to_int(A22, I22), to_int(A23, I23), to_int(A24, I24), to_int(A25, I25),
    COUNT2 is COUNT1+I21+I22+I23+I24+I25,
    COUNT2 =< N,
    two_rows(A11, A12, A13, A14, A15, A21, A22, A23, A24, A25),
    
    to_int(A31, I31), to_int(A32, I32), to_int(A33, I33), to_int(A34, I34), to_int(A35, I35),
    COUNT3 is COUNT2+I31+I32+I33+I34+I35,
    COUNT3 =< N,
    N-COUNT3 =< 10,
    two_rows(A21, A22, A23, A24, A25, A31, A32, A33, A34, A35),
    
    to_int(A41, I41), to_int(A42, I42), to_int(A43, I43), to_int(A44, I44), to_int(A45, I45),
    COUNT4 is COUNT3+I41+I42+I43+I44+I45,
    COUNT4 =< N,
    N-COUNT4 =< 5,
    two_rows(A31, A32, A33, A34, A35, A41, A42, A43, A44, A45),
    
    to_int(A51, I51), to_int(A52, I52), to_int(A53, I53), to_int(A54, I54), to_int(A55, I55),
    COUNT5 is COUNT4+I51+I52+I53+I54+I55,
    N = COUNT5,
	two_rows(A41, A42, A43, A44, A45, A51, A52, A53, A54, A55).

%possible_table(15, A11, A12, A13, A14, A15, A21, A22, A23, A24, A25, A31, A32, A33, A34, A35, A41, A42, A43, A44, A45, A51, A52, A53, A54, A55).
    
%    r	r	r	n	l	n	n	r	n	l	l	l	n	l	l	l	n	r	n	n	l	n	r	r	r
%
%    r	r	r	n	l               ///_\
%    n	n	r	n	l               __/_\
%    l	l	n	l	l               \\_\\
%    l	n	r	n	n               \_/__
%    l	n	r	r	r               \_///
    

