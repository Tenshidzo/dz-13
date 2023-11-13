#include "VideoFilm.h"
#include <iostream>

int main()
{
    setlocale(0, "");
    VideoFilm film1 = { "Пила", "Джеймс Кеммерон", "Хоррор", 4.5, 20.0 };
    VideoFilm film2 = {"Роки", "Лауди бой", "Боевик", 3.9, 15.0 };
    addFilm(film1);
    addFilm(film2);

    displayAllFilms();
    cout << "-----------------------------\n";
    searchByTitle("Пила");
    cout << "-----------------------------\n";
    searchByGenre("Хоррор");
    cout << "-----------------------------\n";
    searchByDirector("Лауди Бой");
    cout << "-----------------------------\n";
    mostPopularInGenre("Боевик");
    cout << "-----------------------------\n";
    removeFilmByTitle("Роки");
    displayAllFilms();
    cout << "-----------------------------\n";
    sortByRating();
    displayAllFilms();
    cout << "-----------------------------\n";
    cout << "Общая стоимость покупки выбранных дисков: " << totalDiskPrice() << endl;

    return 0;
}

