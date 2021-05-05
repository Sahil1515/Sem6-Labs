from django.shortcuts import render

# Create your views here.


from django.http import HttpResponse


def index(request):
    return render(request, 'index.html', context=None)

def metadata(request):
    return render(request, 'metadata.html', context=None)

def reviews(request):
    return render(request, 'reviews.html', context=None)

def publisher(request):
    return render(request, 'publisher.html', context=None)
