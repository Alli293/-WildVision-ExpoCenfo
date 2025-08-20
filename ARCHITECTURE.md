## **4. Arquitectura del Sistema**

```text
┌──────────────────────────┐
│        Usuario / Evento  │
└───────────┬──────────────┘
            │
            ▼
┌──────────────────────────┐
│       ESP32-CAM          │
│                          │
│  ┌───────────────────┐   │
│  │ Captura de Imagen │◄───────── Activado por evento o código
│  └───────────────────┘   │
│            │             │
│            ▼             │
│  ┌───────────────────┐   │
│  │ Procesamiento     │   │
│  │ (Conversión JPEG) │   │
│  └───────────────────┘   │
│            │             │
│   ┌───────────────┐      │
│   │   Almacenaje  │      │
│   └───────────────┘      │
│ SD Card / Servidor       │
└──────────────────────────┘
