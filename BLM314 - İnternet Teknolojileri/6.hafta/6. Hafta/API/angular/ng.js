var app = angular.module('bilmuh', []);
app.controller('KullaniciIslemleriCtrl', function ($scope, $http) {
    $scope.apiurl = "http://localhost:1194/api/";
    $http.get($scope.apiurl + "Kullanici/TumKullanicilariGetir").then(function (response) {
        $scope.kullanicilar = response.data;
    });

    $scope.kullanicisil = function (kid, index) {
        $http.get($scope.apiurl + "Kullanici/KullaniciSil?kid=" + kid).then(function (response) {
            if (response.data == true)
            {
                // silme işlemi sonrası tüm kullanıcılar tekrar çekilir
                $http.get($scope.apiurl + "Kullanici/TumKullanicilariGetir").then(function (response) {
                    $scope.kullanicilar = response.data;
                });
                // silme başarılı ise silinen eleman $scope.kullanicilar.splice ile silinir
                //$scope.kullanicilar.splice(index, 1);
            }
            else
                alert("silme hatalı");
        });
    }
});