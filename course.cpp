void List::remove(int pos)
{
    int count = 1;
    ListNode * temp = head;
    while(count<pos)
    {
        count++;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->next = (temp->next)->next;
    }

}
