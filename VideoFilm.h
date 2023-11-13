#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct VideoFilm {
    string title;
    string director;
    string genre;
    double popularityRating;
    double diskPrice;
};

const int MAX_FILMS = 100;
VideoFilm films[MAX_FILMS];
int filmCount = 0;

// Показ всех записей
void displayAllFilms() {
    cout << "Список видеофильмов:" << endl;
    for (int i = 0; i < filmCount; ++i) {
        cout << "Название: " << films[i].title << " | Режиссер: " << films[i].director
            << " | Жанр: " << films[i].genre << " | Рейтинг: " << films[i].popularityRating
            << " | Цена диска: " << films[i].diskPrice << endl;
    }
}

// Добавление фильма в массив
void addFilm(const VideoFilm& film) {
    if (filmCount < MAX_FILMS) {
        films[filmCount++] = film;
        cout << "Фильм успешно добавлен." << endl;
    }
    else {
        cout << "Массив полон, невозможно добавить больше фильмов." << endl;
    }
}

// Удаление фильма по названию
void removeFilmByTitle(const string& title) {
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].title == title) {
            for (int j = i; j < filmCount - 1; ++j) {
                films[j] = films[j + 1];
            }
            filmCount--;
            cout << "Фильм '" << title << "' удален." << endl;
            return;
        }
    }
    cout << "Фильм с названием '" << title << "' не найден." << endl;
}

// Поиск по названию
void searchByTitle(const string& title) {
    cout << "Фильмы с названием '" << title << "':" << endl;
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].title == title) {
            cout << "Режиссер: " << films[i].director << " | Жанр: " << films[i].genre
                << " | Рейтинг: " << films[i].popularityRating << " | Цена диска: " << films[i].diskPrice << endl;
        }
    }
}

// Поиск по жанру
void searchByGenre(const string& genre) {
    cout << "Фильмы жанра '" << genre << "':" << endl;
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].genre == genre) {
            cout << "Название: " << films[i].title << " | Режиссер: " << films[i].director
                << " | Рейтинг: " << films[i].popularityRating << " | Цена диска: " << films[i].diskPrice << endl;
        }
    }
}

// Поиск по режиссеру
void searchByDirector(const string& director) {
    cout << "Фильмы режиссера '" << director << "':" << endl;
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].director == director) {
            cout << "Название: " << films[i].title << " | Жанр: " << films[i].genre
                << " | Рейтинг: " << films[i].popularityRating << " | Цена диска: " << films[i].diskPrice << endl;
        }
    }
}

// Самый популярный фильм в выбранном жанре
void mostPopularInGenre(const string& genre) {
    double maxRating = 0.0;
    string popularFilm;

    for (int i = 0; i < filmCount; ++i) {
        if (films[i].genre == genre && films[i].popularityRating > maxRating) {
            maxRating = films[i].popularityRating;
            popularFilm = films[i].title;
        }
    }

    if (maxRating > 0.0) {
        cout << "Самый популярный фильм в жанре '" << genre << "': " << popularFilm << " с рейтингом " << maxRating << endl;
    }
    else {
        cout << "Нет фильмов в жанре '" << genre << "'." << endl;
    }
}

// Определить общую стоимость покупки выбранных дисков
double totalDiskPrice() {
    double total = 0.0;
    for (int i = 0; i < filmCount; ++i) {
        total += films[i].diskPrice;
    }
    return total;
}

// Сортировка по рейтингу
bool compareByRating(const VideoFilm& a, const VideoFilm& b) {
    return a.popularityRating > b.popularityRating;
}

void sortByRating() {
    sort(films, films + filmCount, compareByRating);
    cout << "Фильмы отсортированы по рейтингу." << endl;
}