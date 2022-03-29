o_imge = imread('C:\Users\Public\osman\nesne.png');
C = stdfilt(o_imge);
e_degeri = 0.5 * (min(C(:)) + max(C(:)));
deltaT = 0.001;
osm= false;
while ~osm
    A1 = C >= e_degeri;
    A2 = C < e_degeri;
    s1 = sum(C(A1(:)))/numel(C(A1));
    s2 = sum(C(A2(:)))/numel(C(A2));
    yeni_eDegeri = 0.5 * (s1 + s2);
    osm = abs(e_degeri - yeni_eDegeri) < deltaT;
    e_degeri = yeni_eDegeri;
end

T = (C >= e_degeri);
on_imge = uint8(T).*o_imge;
filter1 = [-1, -1, -1; -1, 8, -1; -1, -1, -1];
filtreli_imge1 = imfilter(on_imge, filter1);
son_imge = o_imge + uint8(filtreli_imge1);
imshow(son_imge, []);

G = (C < e_degeri);
arka_imge = uint8(G).*o_imge;
filter2 = (1/48976) * [3609, 6065, 3609; 6065, 10000, 6065; 3609, 6065, 3609];
filtreli_imge2 = imfilter(arka_imge, filter2);
son_imge2 = son_imge + uint8(filtreli_imge2);
figure, imshow(son_imge2);