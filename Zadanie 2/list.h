#ifndef LIST_H
#define LIST_H

struct el {
    int key;
    struct el* next;
};
typedef struct el elListy ;
typedef elListy* lista;

// 1 - dodaj element na początku listy
void add_first_element(lista* list, int a);

// 2 - dodaj element na koncu listy
void add_last_element(lista* list, int a);

// 3 - usun pierwszy element listy
void delete_first_element(lista* list);

// 4 - usun ostatni element listy
void delete_last_element(lista* list);

// 5 - odszukaj zadany element DZIAŁA
void find_the_specified_element(lista* list, int a);

// 6 - dodaj nowy element przed lub za wskazanym
void add_a_new_item_before(lista* list, int a, int newElement);

// dodaj nowy element za wskazanym
void add_a_new_item_after(lista* list, int a, int newElement);

// 7 - usun wskazany element
void remove_the_indicated_item(lista* list, int a);

// wyswietl zawartosc listy
void display_the_contents_of_the_list(lista head);
// wyswietl zawartosc listy od tylu
void display_the_contents_of_the_list_behind(lista head);

// ZADANIE 2

// usuwanie bez rekursji
void non_recursive_delete_occurrence_of_the_indicated(lista* list, int a);
// usuwanie z rekursją
int recursive_delete_occurrence_of_the_indicated(lista* list, int a);

#endif //LIST_H
