#include <iostream>
#include <priority_queue>

int main(){
    int n, k;
    cin >> n >> k;

    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    for (int i=0; i<n; i++){

    }
    return 0;
}



server {
    listen 80;
    server_name localhost;

    # Redirect HTTP to HTTPS in production
    # Uncomment below in production environment
    return 301 https://$host$request_uri;

    location /astronautics/ {
        proxy_pass http://nextjs:3000/astronautics/;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }

    # Serve uploaded files directly through Nginx for better performance
    location /uploads/ {
        alias /usr/share/nginx/html/uploads/;
        expires 1d;
        add_header Cache-Control "public, max-age=86400";
    }

    # Additional security headers
    add_header X-Content-Type-Options nosniff;
    add_header X-Frame-Options SAMEORIGIN;
    add_header X-XSS-Protection "1; mode=block";
}

# HTTPS server (uncomment and configure in production)
server {
    listen 443 ssl;
    server_name localhost;
    ssl_certificate /etc/letsencrypt/live/yourdomain.com/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/yourdomain.com/privkey.pem;
    include /etc/letsencrypt/options-ssl-nginx.conf;
    ssl_dhparam /etc/letsencrypt/ssl-dhparams.pem;

     location /astronautics/ {
        proxy_pass http://nextjs:3000/astronautics/;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }

     location /uploads/ {
         alias /usr/share/nginx/html/uploads/;
         expires 1d;
         add_header Cache-Control "public, max-age=86400";
     }
    add_header X-Content-Type-Options nosniff;
    add_header X-Frame-Options SAMEORIGIN;
    add_header X-XSS-Protection "1; mode=block";
}