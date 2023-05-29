#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "device.h"

struct host_node *head = NULL;
struct host_node *current = NULL;

void printList(){
    struct host_node *p = head;

    //start from beginning
    while (p != NULL) {
        printf("host_name: %s, ip: %s, mac: %s \n", (p->host).host_name, (p->host).ip_addr_str, (p->host).mac_addr_str);
        p = p->next;
    }
}

void insertHost(host_t host){
    struct host_node *nh = (struct host_node*)malloc(sizeof(struct host_node));
    nh->host = host;
    nh->next = NULL;

    if (head == NULL){
        head = nh;
        return;
    }

    struct host_node *node = head;

    while(node->next != NULL) {
        node = node->next;
    }

    node->next = nh;
    return;
}

int searchList(char ip_add_str[256]) {
    struct host_node *tmp = head;

    while (tmp != NULL) {
        if (strcmp((tmp->host).ip_addr_str, ip_add_str) == 0) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}