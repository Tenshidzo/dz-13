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

// ����� ���� �������
void displayAllFilms() {
    cout << "������ ������������:" << endl;
    for (int i = 0; i < filmCount; ++i) {
        cout << "��������: " << films[i].title << " | ��������: " << films[i].director
            << " | ����: " << films[i].genre << " | �������: " << films[i].popularityRating
            << " | ���� �����: " << films[i].diskPrice << endl;
    }
}

// ���������� ������ � ������
void addFilm(const VideoFilm& film) {
    if (filmCount < MAX_FILMS) {
        films[filmCount++] = film;
        cout << "����� ������� ��������." << endl;
    }
    else {
        cout << "������ �����, ���������� �������� ������ �������." << endl;
    }
}

// �������� ������ �� ��������
void removeFilmByTitle(const string& title) {
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].title == title) {
            for (int j = i; j < filmCount - 1; ++j) {
                films[j] = films[j + 1];
            }
            filmCount--;
            cout << "����� '" << title << "' ������." << endl;
            return;
        }
    }
    cout << "����� � ��������� '" << title << "' �� ������." << endl;
}

// ����� �� ��������
void searchByTitle(const string& title) {
    cout << "������ � ��������� '" << title << "':" << endl;
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].title == title) {
            cout << "��������: " << films[i].director << " | ����: " << films[i].genre
                << " | �������: " << films[i].popularityRating << " | ���� �����: " << films[i].diskPrice << endl;
        }
    }
}

// ����� �� �����
void searchByGenre(const string& genre) {
    cout << "������ ����� '" << genre << "':" << endl;
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].genre == genre) {
            cout << "��������: " << films[i].title << " | ��������: " << films[i].director
                << " | �������: " << films[i].popularityRating << " | ���� �����: " << films[i].diskPrice << endl;
        }
    }
}

// ����� �� ���������
void searchByDirector(const string& director) {
    cout << "������ ��������� '" << director << "':" << endl;
    for (int i = 0; i < filmCount; ++i) {
        if (films[i].director == director) {
            cout << "��������: " << films[i].title << " | ����: " << films[i].genre
                << " | �������: " << films[i].popularityRating << " | ���� �����: " << films[i].diskPrice << endl;
        }
    }
}

// ����� ���������� ����� � ��������� �����
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
        cout << "����� ���������� ����� � ����� '" << genre << "': " << popularFilm << " � ��������� " << maxRating << endl;
    }
    else {
        cout << "��� ������� � ����� '" << genre << "'." << endl;
    }
}

// ���������� ����� ��������� ������� ��������� ������
double totalDiskPrice() {
    double total = 0.0;
    for (int i = 0; i < filmCount; ++i) {
        total += films[i].diskPrice;
    }
    return total;
}

// ���������� �� ��������
bool compareByRating(const VideoFilm& a, const VideoFilm& b) {
    return a.popularityRating > b.popularityRating;
}

void sortByRating() {
    sort(films, films + filmCount, compareByRating);
    cout << "������ ������������� �� ��������." << endl;
}