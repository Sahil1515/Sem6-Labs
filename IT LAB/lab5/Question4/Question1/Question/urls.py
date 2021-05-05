

from django.contrib import admin
from django.urls import path

from Question import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.index),
    path('magzine-cover', views.magzine_cover),

]
