from django.shortcuts import render

# Create your views here.


from django.http import HttpResponse


def index(request):

    arithmetic_operators = ["+", "-", "*", "/", "**"]
    context = {'mylist': arithmetic_operators}
    return render(request, 'index.html', context=context)
