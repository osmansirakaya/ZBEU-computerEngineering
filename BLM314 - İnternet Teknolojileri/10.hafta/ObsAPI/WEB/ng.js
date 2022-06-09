var app = angular.module('ZBEUN', []);
app.controller('OBSNOTCtrl', function ($scope, $http) {
    $http.get("https://localhost:44396/api/Not/TumNotlariGetir").then(function (response) {
            $scope.notlar = response.data;
        });
});