from django.shortcuts import render

# Create your views here.


from django.http import HttpResponse


def index(request):
    return render(request, 'index.html', context=None)

def magzine_cover(request):
    return render(request, 'magzine_cover.html', context=None)
