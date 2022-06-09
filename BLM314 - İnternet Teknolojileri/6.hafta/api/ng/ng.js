var app = angular.module("bilMuh", []);

app.controller("kullaniciIslemleriCtrl", function ($scope, $http) {
    $scope.apiurl = "https://localhost:44308/api/";
    $http.get($scope.apiurl+"kullanici/tumKullanicilariGetir").then(function (response) {
        $scope.kullanicilar = response.data;
    });

    $scope.kullaniciSil = function (kid, index) {
        $http.get($scope.apiurl +"kullanici/kullaniciSil?kid=" + kid).then(function (response) {
            if (response.data == true) {
                // silme işleminden sonra verileri geri çekıyor
                $http.get($scope.apiurl +"kullanici/tumKullanicilariGetir").then(function (response) {
                    $scope.kullanicilar = response.data;
                });
                // silme basarılı ise silinen eleman $scope.kullanicilar.splice index
                //$scope.kullanicilar.splice(index, 1);

            }  
            else
                alert("silme hatali");
        });
    }
});
