

from django.contrib import admin
from django.urls import path

from Question import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.index),
    path('metadata', views.metadata),
    path('reviews', views.reviews),
    path('publisher', views.publisher),

]
